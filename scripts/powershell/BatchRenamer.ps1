

foreach ($file in Get-ChildItem -Path "C:\Users\randy\OneDrive\Desktop\CS380\PowerShell_Scripts\TextFiles" -File) {
    Rename-Item $file.FullName -NewName ("OLD_" + $file.Name)
}