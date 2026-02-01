[Object]@{
    "Current Date/Time" = Get-Date
    "Host Name" = hostname
    "Current User" = whoami
    "Disk Usage" = "($(Get-PSDrive -Name C).Free / 1GB)) GB /  + $(((Get-Volume -DriveLetter C).Size / 1GB)) GB"
} | Format-Table