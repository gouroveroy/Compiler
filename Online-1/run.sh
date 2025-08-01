dir=$1
cd $dir

flex -o 2105017.cpp 2105017.l
g++ 2105017.cpp -o 2105017.out
./2105017.out input.txt

cd ..