------- Metadata --------------------------------------------------------------
-- VarFileInit
-- Author: Lucky Penny
-- Description: Creates all variables files with default values.
-- License: Creative Commons BY-NC-SA 3.0
-- Version: 0.0.3
--
-- Initialize(): As described
-------------------------------------------------------------------------------


-- Create the files for the variables unless it already exists
function Initialize()
    -- variables.var
    local doRefreshForVariables = GenerateVarsFile("variables", "TemplateVariablesDefault", "Variables",        "")
    -- clocks.var
    local doRefreshForClocks    = GenerateVarsFile("clocks",    "TemplateClocksDefault",    "ClocksSettings",   "")
    -- disks.var
    local doRefreshForDisks     = GenerateVarsFile("disks",     "TemplateDisksDefault",     "DisksSettings",    "Disk1")
    -- network.var
    local doRefreshForNetwork   = GenerateVarsFile("network",   "TemplateNetworkDefault",   "NetworkSettings",  "")
    -- fortune.var
    local doRefreshForFortune   = GenerateVarsFile("fortune",   "TemplateFortuneDefault",   "FortuneSettings",  "")
    -- gpus.var
    local doRefreshForGpus      = GenerateVarsFile("gpus",      "TemplateGpusDefault",      "GpusSettings",     "Gpu1")
    -- cpu.var
    local doRefreshForCpu       = GenerateVarsFile("cpu",       "TemplateCpuDefault",       "CpuSettings",      "Cpu1")
    
    if doRefreshForVariables
     or doRefreshForClocks
     or doRefreshForDisks
     or doRefreshForNetwork
     or doRefreshForFortune
     or doRefreshForGpus
     or doRefreshForCpu then
        SKIN:Bang("!Refresh") end
end

-- Generator for var files
function GenerateVarsFile(varFileName,templateFileName,name,substitute)
    dofile(SKIN:ReplaceVariables("#@#").."FileHelper.lua")

    if next(ReadIni(SKIN:ReplaceVariables("#@#")..varFileName..".var")) then return false end
    local variables = {}

    local templateFileVars = ReadFile(SKIN:ReplaceVariables("#@#").."Templates\\"..templateFileName..".inc")
    variables = GenerateMetadata(variables,name,"Lucky Penny","Variables for the "..varFileName,"0.0.3")
    table.insert(variables,"[Variables]")

    for _,value in ipairs(templateFileVars) do
        local str = ""
        if value:find("|") then
            str = value:gsub("|",substitute)
        else
            str = value
        end
        table.insert(variables,str)
    end

    WriteFile(table.concat(variables,"\n"),SKIN:ReplaceVariables("#@#")..varFileName..".var")

    return true
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
