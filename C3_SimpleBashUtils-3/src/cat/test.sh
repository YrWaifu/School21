#!/ bin / bash

GREEN="\033[92m"
RED="\033[91m"
NORMAL="\033[0m"

echo "------------------------TEST1.---------------------------"
echo "------------------------1 File.--------------------------"

for filename in test_file1.txt test_file2.txt test_file3.txt test_file4.txt
do
TEST="$filename"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
diff s21_cat.txt cat.txt > 3.txt

if [ -s 3.txt ]
then
echo -e "$RED 𝗙𝗔𝗜𝗟 $NORMAL"
else
echo -e "$GREEN 𝗦𝗨𝗖𝗖𝗘𝗦𝗦 $NORMAL"
fi
rm s21_cat.txt cat.txt 3.txt
for flag in -b -e -n -s -t  
do
TEST="$flag $filename"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
diff s21_cat.txt cat.txt > 3.txt

if [ -s 3.txt ]
then
echo -e "$RED 𝗙𝗔𝗜𝗟 $NORMAL"
else
echo -e "$GREEN 𝗦𝗨𝗖𝗖𝗘𝗦𝗦 $NORMAL"
fi
rm s21_cat.txt cat.txt 3.txt
done
done

echo "------------------------TEST2.---------------------------"
echo "--------------------A lot of File.-----------------------"

filename="test_file1.txt test_file2.txt test_file3.txt test_file4.txt"
TEST="$filename"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
diff s21_cat.txt cat.txt > 3.txt

if [ -s 3.txt ]
then
echo -e "$RED 𝗙𝗔𝗜𝗟 $NORMAL"
else
echo -e "$GREEN 𝗦𝗨𝗖𝗖𝗘𝗦𝗦 $NORMAL"
fi
rm s21_cat.txt cat.txt 3.txt
for flag in -b -e -n -s -t 
do
TEST="$flag $filename"
echo "$TEST"
./s21_cat $TEST > s21_cat.txt
cat $TEST > cat.txt
diff s21_cat.txt cat.txt > 3.txt

if [ -s 3.txt ]
then
echo -e "$RED 𝗙𝗔𝗜𝗟 $NORMAL"
else
echo -e "$GREEN 𝗦𝗨𝗖𝗖𝗘𝗦𝗦 $NORMAL"
fi
rm s21_cat.txt cat.txt 3.txt
done