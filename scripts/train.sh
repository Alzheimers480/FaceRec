~/cv-dev/create_csv.py ~/cv-dev/testdata/model > ~/cv-dev/faces.csv
rm ~/cv-dev/outfiles/result.text
~/cv-dev/faces train ~/cv-dev/faces.csv
time ~/cv-dev/scripts/recQA.sh -f "%e"
