sh compile.sh $1
if [ $? -ne 0 ]; then
    echo "Compilation of $1 is failed"
    exit 1
fi
echo "Compilation of $1 succeeded. Starting the program."
./a.out