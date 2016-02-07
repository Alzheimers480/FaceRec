~/cv-dev/faces train ~/cv-dev/faces.csv
for folder in ~/cv-dev/testdata/test/*; do
    [ -d "$folder" ] && cd "$folder" && ~/cv-dev/scripts/tester.sh
done;
