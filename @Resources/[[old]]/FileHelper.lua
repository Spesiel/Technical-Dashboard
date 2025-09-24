------- Metadata --------------------------------------------------------------
-- FileHelper
-- Author: Lucky Penny
-- Description: Methods for file manipulations within the skin.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.3
--
-- ReadIni(filepath): Reads an ini file and returns it as a table.
-- WriteIni(inputtable,filepath): Writes the ini data to file.
-- ReadFile(filepath): Reads a file as it is and returns it as a table.
-- WriteFile(inputtable,filepath): Writes the data to file.
-- GenerateFile(varForTotal,templateFileName,itemBaseName): Generates
--				generated.inc file based on informations
-- GenerateFileConfig(varForTotal,varFileName,templateForDefault,
--				templateForMeters,groupName,itemBaseName,identifier): Generates
--				generated.inc and variables file depending on context
-------------------------------------------------------------------------------


function ReadIni(filepath)
	local file = io.open(filepath,"r")
	if file==nil then print("ReadIni: unable to open " .. filepath) return {} end
	local table, section = {}
	local num = 0
	for line in file:lines() do
		num = num + 1
		if not line:match("^%s-;") then
			local key, command = line:match("^([^=]+)=(.*)")
			if line:match("^%s-%[.+") then
				section = line:match("^%s-%[([^%]]+)")
				if not table[section] then table[section] = {} end
			elseif key and command and section then
				table[section][key:match("^s*(%S*)%s*$")] = command:match("^s*(.-)%s*$")
			elseif #line > 0 and section and not key or command then
				print("ReadIni: " .. filepath .. " line " .. num .. ": Invalid property or value.")
			end
		end
	end
	if not section then print("No sections found in " .. filepath) end
	file:close()
	return table
end

function WriteIni(inputtable, filepath)
	assert(type(inputtable) == "table", ("WriteIni must receive a table. Received %s instead."):format(type(inputtable)))

	local file = assert(io.open(filepath, "w+"), "WriteIni: Unable to open " .. filepath)

    if inputtable.Metadata ~= nil then
        file:write("[Metadata]","\n")
        file:write(("Name=%s"):format(inputtable.Metadata.Name),"\n")
        file:write(("Author=%s"):format(inputtable.Metadata.Author),"\n")
        file:write(("Information=%s"):format(inputtable.Metadata.Information),"\n")
        file:write("License=Creative Commons BY-NC-SA 3.0","\n")
        file:write(("Version=%s"):format(inputtable.Metadata.Version),"\n\n")
    end

	for section, contents in pairs(inputtable) do
        if section ~= "Metadata" then
            file:write(("[%s]"):format(section),"\n")
            for key, value in pairs(contents) do
				-- It"s a comment
				if key:sub(1,1)==";" then
					file:write(("%s"):format(value),"\n")
				-- It"s data
                else
					file:write(("%s=%s"):format(key,value),"\n")
				end
            end
            file:write("\n")
        end
	end

	file:close()
end

function ReadFile(filepath)
	local file = io.open(filepath,"r")
	if file==nil then print("ReadFile: Unable to open " .. filepath) return {} end

	local content = {}
	for line in file:lines() do table.insert(content,line) end
    file:close()
	return content
end

function WriteFile(inputtable,filepath)
	local file = assert(io.open(filepath, "w+"), "WriteFile: Unable to open " .. filepath)
	file:write(inputtable)
	file:close()
end

function GenerateMetadata(inputtable,name,author,information,version)
	table.insert(inputtable,"[Metadata]")
	table.insert(inputtable,"Name="..name)
    table.insert(inputtable,"Author="..author)
    table.insert(inputtable,"Information="..information)
    table.insert(inputtable,"License=Creative Commons BY-NC-SA 3.0")
    table.insert(inputtable,"Version="..version.."\n")
    return inputtable
end

function GenerateFile(varForTotal,templateFileName,itemBaseName)
    local varTotal = SKIN:GetVariable(varForTotal)

    local needRefresh = next(ReadIni(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc"))
    -- Loads the template
    local template = {}
    template = ReadFile(SKIN:ReplaceVariables("#CurrentPath#")..templateFileName..".inc")

    -- loop through the data for each item
    local content = {}
    for loop=1,varTotal,1 do
        local currentItem = itemBaseName..loop
        for _,value in ipairs(template) do
            local str = ""
            if value:find("|") then
                str = value:gsub("|",currentItem)
            else
                str = value
            end
            table.insert(content,str)
        end
    end
    WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")

    if needRefresh==nil then SKIN:Bang("!Refresh") end
end

function GenerateFileConfig(varFileName,templateForDefault,templateForMeters,groupName,itemBaseName,identifier)
    local varTotal = SKIN:GetVariable(groupName.."Total")

    local varFile = ReadIni(SKIN:ReplaceVariables("#@#")..varFileName..".var")
    local refreshNeeded = false
    if next(varFile)==nil then refreshNeeded = true end
    local generated = ReadIni(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")
    local refreshGenerated = false
    if next(generated)==nil then refreshGenerated = true end

    local templateVars = ReadFile(SKIN:ReplaceVariables("#@#").."Templates\\"..templateForDefault..".inc")
    local templateMeters = ReadFile(SKIN:ReplaceVariables("#CurrentPath#")..templateForMeters..".inc")

    -- loop through the data for each disk
    local variables = GenerateMetadata({},groupName.."Settings","Lucky Penny","Variables for the "..varFileName,"0.0.3")
    table.insert(variables,"[Variables]")
    table.insert(variables,groupName.."Total="..varTotal)
    local content = {}
    for loop=1,varTotal,1 do
        local currentItem = itemBaseName..loop

        if not varFile.Variables[currentItem..identifier] then refreshNeeded    = true end
        if not generated[currentItem.."Title"]            then refreshGenerated = true end
        
        for _,value in ipairs(templateMeters) do
            local str = ""
            if value:find("|") then
                str = value:gsub("|",currentItem)
            else
                str = value
            end
            table.insert(content,str)
        end

        for _,value in ipairs(templateVars) do
            local str = ""
            if value:find("|") then
                str = value:gsub("|",currentItem)
            else
                str = value
            end
            if str:find(groupName.."Total")==nil then table.insert(variables,str) end
        end
    end

    if generated[itemBaseName..(tonumber(varTotal)+1).."Title"] then
        refreshGenerated = true
    end

    -- Writes the values to files
    if refreshNeeded or refreshGenerated then
        WriteFile(table.concat(variables,"\n"),SKIN:ReplaceVariables("#@#")..varFileName..".var")
        WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")

        SKIN:Bang("!RefreshGroup "..groupName)
    end
end
