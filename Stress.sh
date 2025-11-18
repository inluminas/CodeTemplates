set -e
g++ file.cpp -o file
g++ gen.cpp -o gen
g++ brute.cpp -o brute
#g++ checker.cpp -o checker
for((i = 1; i <= 200 ; ++i)); do
    ./gen $i > input_file
    ./file < input_file > myAnswer
    ./brute < input_file > correctAnswer
    #./checker > checker_log
    if ! diff -u correctAnswer myAnswer ; then
        echo "Mismatch found on test "  $i
        exit 0;
    fi
    
    echo "Passed test: "  $i
done
