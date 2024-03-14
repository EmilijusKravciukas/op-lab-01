## STUDENT MARK EVALUTAION AND SORTING SYSTEM
# DESCRIPTION
Simple console based application that allows the student data (read from file and manual input are both supported) to be sorted in one of several ways. Keep in mind that the current release (v0.4) is for Windows based systems, attempting to run it on a Linux system will cause errors.
# DESCRIPTION
> Sorting of students by their average mark, median, name and surname
> Reading student data from a file, provided it follows the provided format (see FORMATTING section)
> Sorting students into separate files based on their academic provess
> Random student and mark generation for testing purposes
# USAGE GUIDE
**1. Download the latest release**
After downloading the latest release extract it anywhere.
**2. Build the solution**
You will have to use a c++ compiler. Import the extracted folder and press Build and Run button.
**3. Using the application**
Upon building and launching the program you will be presented with a console interface. Input numbers (1 to 4 in the starting menu) to navigate the interface.
# FORMATTING
The program only reads data files that follow the following formatting:
`Vardas                   Pavarde                    ND1       ND2       ND3      Egz.`
`Vardas1                 Pavarde1                      8         9         4        10`
`Vardas2                 Pavarde2                      9         7         9         2`
`...                                                                                  `
Vardas and Pavarde refer to Name and Surname values, ND(number) shows the homework mark along with its iterator, Egz. refers to the exam mark. Number of homework marks can be varied indefinitely, yet they cannot be equal to zero. Exam mark is required.
