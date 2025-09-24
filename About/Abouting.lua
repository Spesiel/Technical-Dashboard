------- Metadata --------------------------------------------------------------
-- Abouting
-- Author: Lucky Penny
-- Description: Lists widgets and display a list of them and their options.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.3
--
-- Initialize(): As described. 
-------------------------------------------------------------------------------


-- Load all schemes from file
function Initialize()
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    -- Lists the widgets for the skin
    local directory = os.tmpname()
    os.execute("DIR \""..SKIN:ReplaceVariables("#RootConfigPath#").."\" /A:D /B >> "..directory)

    local needRefresh = next(ReadIni(SKIN:ReplaceVariables("#CurrentPath#").."generated.inc"))
    -- Loads the template
    local template = {}
    template = ReadFile(SKIN:ReplaceVariables("#CurrentPath#").."TemplateAboutMeters.inc")

    -- loop through the data for each item
    local listing = io.open(directory,"r")
    local content = {}
    local counter = 1
    for line in listing:lines() do
        if line:find("@")==nil and line:find(".git")==nil
          and line:find("About")==nil and line:find("ScaleSettings")==nil and line:find("Themes")==nil then
            for _,value in ipairs(template) do
                local str = ""
                if value:find("|") then
                    str = value:gsub("|",line)
                elseif value:find("Y=") and counter == 1 then
                    str = "Y=40"
                else
                    str = value
                end
                table.insert(content,str)
            end
            counter = counter + 1
        end
    end
    WriteFile(table.concat(content,"\n"),SKIN:ReplaceVariables("#CurrentPath#").."generated.inc")
    listing:close()

    if needRefresh==nil then SKIN:Bang("!Refresh") end
end
