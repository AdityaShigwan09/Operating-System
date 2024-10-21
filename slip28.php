<!-- Q.1) Write a program to read a flat file “student.dat”, calculate the percentage 
and display the data from file in tabular format.(Student.dat file contains rollno, 
name, OS, WT, DS, Python, Java, CN ) -->

<?php

function readStudentData($fileName) {
    $data = [];
    $file = fopen($fileName, 'r');
    
    while (($line = fgetcsv($file)) !== FALSE) {
        $rollno = $line[0];
        $name = $line[1];
        $marks = array_slice($line, 2); // Get marks from the third element onwards
        $data[] = ['rollno' => $rollno, 'name' => $name, 'marks' => array_map('floatval', $marks)];
    }
    
    fclose($file);
    return $data;
}


function calculatePercentage($marks) {
    $totalMarks = array_sum($marks);
    $percentage = ($totalMarks / (count($marks) * 100)) * 100; // Assuming each subject is out of 100
    return $percentage;
}

function displayData($data) {
    echo "<table border='1'>";
    echo "<tr><th>Roll No</th><th>Name</th><th>OS</th><th>WT</th><th>DS</th><th>Python</th><th>Java</th><th>CN</th><th>Percentage</th></tr>";
    foreach ($data as $student) {
        $percentage = calculatePercentage($student['marks']);
        echo "<tr>";
        echo "<td>{$student['rollno']}</td>";
        echo "<td>{$student['name']}</td>";
        echo "<td>" . implode("</td><td>", $student['marks']) . "</td>";
        echo "<td>" . number_format($percentage, 2) . "%</td>";
        echo "</tr>";
    }
    
    echo "</table>";
}


    $fileName = 'student.dat';
    $studentData = readStudentData($fileName);
    displayData($studentData);


?>