for folder in ~/cv-dev/testdata/test/*; do
    [ -d "$folder" ] && cd "$folder" && ~/cv-dev/scripts/tester.sh
done;
