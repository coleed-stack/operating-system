$file = Get-Item "C:\Users\randy\OneDrive\Desktop\CS380\PowerShell_Scripts\TextFiles\server.log.txt"

(Select-String -Path $file -Pattern "Error" -AllMatches).Matches.Count