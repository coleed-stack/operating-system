Get-Process | Sort-Object WS -Descending | Select-Object -First 5 Name, Id, @{Name="Mem Usage(MB)";Expression={[math]::round($_.ws / 1mb)}} | Format-Table
