#Shell Programming

echo "Enter a";
read a;
echo "Enter b";
read b;
echo "Addition of $a and $b is $((a+b))";

echo "Enter num";
read n;
if [ $((n%2)) -eq 0 ]
then 
echo "$n is even";
else 
echo "$n is odd";
fi

echo "Enter the total no of elements";
read n;
sum=0;
while [ $((n)) -ge 1 ]
do
    echo "Enter the num";
    read x;
    sum=$((sum+x));
    n=$((n-1));
done
echo "The sum is $sum";


echo "Enter your age";
read age
if [ $((age)) -ge 18 ]
then
echo "You are eligible for voting";
else 
echo "You are not eligible for voting";
fi


echo "Enter the num whose factorial you need to find";
read n;
f=1;
for((i=1;i<=n;i++))
do 
    f=$((f*i));
done

echo "Factorial is $f"


function valid
{
    echo "Enter username";
    read username;
    echo "Enter password";
    read password;
    
    user="Sai";
    pass="ssk";
    
    if [[ $user == $username && $pass == $password ]]
    then
    echo "Valid"
    else 
    echo "not Valid"
    fi
    
}
valid

