echo "# LeetCode in C++" > Readme.md

# sort the folder names by numbers and print them to Readme.md
ls -1vd */ | while read -r folder; do
    foldername="${folder%//}"  # remove the trailing slash
    
    echo "" >> Readme.md
    echo "## $foldername" >> Readme.md
    
    # get into all the subfolders and print the file names
    ls -1v $foldername/*.cpp | while read -r file; do
        filename="${file##*/}"  # extract the file name from the path
        filename="${filename%.*}"  # remove the file extension
        display_name="${filename//-/ }"  # replace all "-" with space
        echo "- [$display_name](./$foldername/$filename.cpp)" >> Readme.md
    done

    # sleep 100
done
