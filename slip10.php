<!-- Write a script to accept two integers(Use html form having 2 textboxes). Write a PHP script to,
a. Find mod of the two numbers.
b. Find the power of first number raised to the second.
c. Find the sum of first n numbers (considering first number as n)
d. Find the factorial of second number.
(Write separate function for each of the above operations.) -->


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<style>
</style>
<body>
    <form method="post">
        <label >1st Value</label>
        <input type="text" name="num1" placeholder="Enter 1st Value "> <br>
        <label >2nd value</label>
        <input type="text" name="num2" placeholder="Enter 2nd Value "><br><br>

        <input type="radio" name="check" value=1> <label >Mod of the two numbers.</label> <br>
        <input type="radio" name="check" value=2> <label >Power of first number raised to the second.</label><br>
        <input type="radio" name="check" value=3> <label >Sum of first n numbers</label><br>
        <input type="radio" name="check" value=4> <label >Factorial of second number</label><br><br>

        <input type="submit" name="submit" value="Submit">
    </form>
</body>
</html>


<?php

# A. Find mod of the two numbers.

function mod($a,$b){
    return $a % $b;
}

# B. Find the power of first number raised to the second.

function power($a,$b){
    return $a**$b;
}

# C. Find the sum of first n numbers (considering first number as n)

function sum($a){

$as = (string)$a;
$res= 0;

for ($i = 0; $i < strlen($as); $i++) {
    $res += (int)$as[$i];
}
return $res;
}


# D. Find the factorial of second number.
function factorial($b) {

    $result = 1;

    for ($i = 1; $i <= $b; $i++) {
        $result *= $i;
    }

    return $result; 
}


#Main Code
$n1=(int)$_POST['num1'];
$n2=(int)$_POST['num2'];

$c=$_POST['check'];


if($c==1){
    $ans=mod($n1,$n2);
    echo "<h1>Result</h1> <br> <p>Mod of the two numbers.</p>"
    ,$n1," % ",$n2," = ",$ans;
}
else if($c==2){
    $ans=power($n1,$n2);
    echo "<h1>Result</h1> <br> <p> Power of first number raised to the second.</p>"
    ,$n1," <sup>",$n2," </sup> = ",$ans;
}
else if($c==3){
    $ans=sum($n1);
    echo "<h1>Result</h1> <br> <p>Sum of first n numbers</p>"
    ,$n1," = ",$ans;
}
else if($c==4){
    $ans=factorial($n2);
    echo "<h1>Result</h1> <br> <p>  Factorial of second number.</p>"
    ,$n2," = ",$ans;
}



?>