#!/ bin / bash

GREEN="\033[92m"
RED="\033[91m"
NORMAL="\033[0m"

echo "------------------------TEST1.---------------------------"
echo "------------------------1 File.--------------------------"

for filename in test_file1.txt test_file2.txt test_file3.txt test_file4.txt
do
TEST="ds $filename"
echo "$TEST"
./s21_grep $TEST > s21_grep.txt
grep $TEST > grep.txt
diff s21_grep.txt grep.txt > 3.txt

if [ -s 3.txt ]
then
echo -e "$RED 𝗙𝗔𝗜𝗟 $NORMAL"
else
echo -e "$GREEN 𝗦𝗨𝗖𝗖𝗘𝗦𝗦 $NORMAL"
fi
rm s21_grep.txt grep.txt 3.txt
for flag in -h -i -v -c -n -o
do
TEST="$flag ds $filename"
echo "$TEST"
./s21_grep $TEST > s21_grep.txt
grep $TEST > grep.txt
diff s21_grep.txt grep.txt > 3.txt

if [ -s 3.txt ]
then
echo -e "$RED 𝗙𝗔𝗜𝗟 $NORMAL"
else
echo -e "$GREEN 𝗦𝗨𝗖𝗖𝗘𝗦𝗦 $NORMAL"
fi
rm s21_grep.txt grep.txt 3.txt
done
for tests in "[1-5] $filename" "-l ds *.txt" "-e sg -e ds -e sf $filename" "-s ds $filename test_file5.txt"
do
echo "$tests"
./s21_grep $tests > s21_grep.txt
grep $tests > grep.txt
diff s21_grep.txt grep.txt > 3.txt

if [ -s 3.txt ]
then
echo -e "$RED 𝗙𝗔𝗜𝗟 $NORMAL"
else
echo -e "$GREEN 𝗦𝗨𝗖𝗖𝗘𝗦𝗦 $NORMAL"
fi
rm s21_grep.txt grep.txt 3.txt
done
done

echo "------------------------TEST2.---------------------------"
echo "--------------------A lot of File.-----------------------"

filename="test_file1.txt test_file2.txt test_file3.txt test_file4.txt"
TEST="ds $filename"
echo "$TEST"
./s21_grep $TEST > s21_grep.txt
grep $TEST > grep.txt
diff s21_grep.txt grep.txt > 3.txt

if [ -s 3.txt ]
then
echo -e "$RED 𝗙𝗔𝗜𝗟 $NORMAL"
else
echo -e "$GREEN 𝗦𝗨𝗖𝗖𝗘𝗦𝗦 $NORMAL"
fi
rm s21_grep.txt grep.txt 3.txt
for flag in -h -i -v -c -n -o
do
TEST="$flag ds $filename"
echo "$TEST"
./s21_grep $TEST > s21_grep.txt
grep $TEST > grep.txt
diff s21_grep.txt grep.txt > 3.txt

if [ -s 3.txt ]
then
echo -e "$RED 𝗙𝗔𝗜𝗟 $NORMAL"
else
echo -e "$GREEN 𝗦𝗨𝗖𝗖𝗘𝗦𝗦 $NORMAL"
fi
rm s21_grep.txt grep.txt 3.txt
done
for tests in "[1-5] $filename" "-l ds *.txt" "-e sg -e ds -e sf $filename" "-s ds $filename test_file5.txt"
do
echo "$tests"
./s21_grep $tests > s21_grep.txt
grep $tests > grep.txt
diff s21_grep.txt grep.txt > 3.txt

if [ -s 3.txt ]
then
echo -e "$RED 𝗙𝗔𝗜𝗟 $NORMAL"
else
echo -e "$GREEN 𝗦𝗨𝗖𝗖𝗘𝗦𝗦 $NORMAL"
fi
rm s21_grep.txt grep.txt 3.txt
done