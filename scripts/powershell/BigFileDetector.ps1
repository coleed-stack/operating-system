$file = $args[0]

if (Test-Path -Path $file) {
    $fileInfo = Get-Item $file
    if ($fileInfo.Length -lt 1MB) {
        Write-Host "File size is within limits: $($fileInfo.Length)"
    } else {
        Write-Host "Warning: File is too large: $($fileInfo.Length)"
    }
} else {
    Write-Host "File does not Exist"
}