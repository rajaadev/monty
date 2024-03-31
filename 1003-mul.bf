>,>,<<                           // Read two digits from stdin
convert atoi
+++++ +                          // Set cell(0) to 5
[                                // Loop to convert ASCII digits to integers
 >----- ---                      // Subtract 48 from cell(0) twice (ASCII conversion)
 <<-
]
multiply two integers
>[
 >[>+>+<<-]                     // Move cell(0) to cell(1) and cell(2)
 >[<+>-]                         // Multiply cell(1) and cell(2), result in cell(1)
 <<-
]
separate two digits inputed
>[-]>+> >+++++ +++++<            // Separate the two digits into cell(0) and cell(1)
[
 - >- [>>>]+++++ +++++<<+        // Move the first digit to cell(2)
 [<<<]>>>>
]
<-
<+++++ +++++>>>[-<<<->>>]<<<    // Move the second digit to cell(1)
convert itoa
<+++++ +                         // Set cell(0) to 5
[
 >+++++ +++>                     // Add 48 to cell(0) (convert back to ASCII)
 [+++++ +++>]
 <[<]>-
]
print with newline
>>[.<<]<[<<]>>.                  // Print the result with a newline
>>,.                             // Print a comma and space
