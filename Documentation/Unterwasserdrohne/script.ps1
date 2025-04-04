# Define the folder path. Update this with your target folder.
$TargetFolder = "."

# Check if the folder exists
if (-Not (Test-Path $TargetFolder)) {
    Write-Host "The specified folder does not exist: $TargetFolder" -ForegroundColor Red
    exit
}

# Get all files in the folder and its subfolders that start with '_index_of'
$FilesToDelete = Get-ChildItem -Path $TargetFolder -Recurse -File -Filter "_index_of*"

if ($FilesToDelete.Count -eq 0) {
    Write-Host "No matching files found to delete." -ForegroundColor Yellow
    exit
}

# Loop through and delete the files
foreach ($File in $FilesToDelete) {
    try {
        Remove-Item -Path $File.FullName -Force
        Write-Host "Deleted: $($File.FullName)" -ForegroundColor Green
    } catch {
        Write-Host "Failed to delete: $($File.FullName). Error: $($_.Exception.Message)" -ForegroundColor Red
    }
}

Write-Host "File deletion process completed." -ForegroundColor Cyan
