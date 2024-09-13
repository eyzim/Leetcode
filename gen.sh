
echo "# LeetCode in C++" > Readme.md
# count all cpp files
cpp_files=$(find . -name "*.cpp" | wc -l)
echo "Date: $(date +'%Y/%m/%d')" >> Readme.md
echo "Total: $cpp_files" >> Readme.md
echo "---" >> Readme.md
echo "" >> Readme.md
echo "## Table of Contents" >> Readme.md
echo "" >> Readme.md

# loop through the folder names and print the links
ls -1vd */ | while read -r folder; do
    foldername="${folder%//}"  # remove the trailing slash
    echo "- [$foldername](#$foldername)" >> Readme.md
done

echo "" >> Readme.md

# loop through the folder names and print the section headers
ls -1vd */ | while read -r folder; do
    foldername="${folder%//}"  # remove the trailing slash
    echo "## $foldername" >> Readme.md

    # get into all the subfolders and print the file names
    ls -1v $foldername/*.cpp | while read -r file; do
        filename="${file##*/}"  # extract the file name from the path
        filename="${filename%.*}"  # remove the file extension
        display_name="${filename//-/ }"  # replace all "-" with space
        echo "- [$display_name](./$foldername/$filename.cpp)" >> Readme.md
    done

    echo "" >> Readme.md
done
