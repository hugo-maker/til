# Summary of Chapter 11 to 15

## Relational Operators

- Don't compare two unlike data values (If you want to, use a typecast to keep the values the same data type)

## If Statements

- if (condition) {block of one or more C statements;}
- if (condition) {block of one or more C statements;} else {block of one or more C statements;}
- Don't put semicolon after the if or else (semicolons go only at the end of complete statements)

## Logical Operators

- Rewrite a logical expression to avoid using ! by reversing the logic as long as you can
- Don't combine too many relational operators in a single expression (if you do so, it makes difficult to read and maintain)
- Use ample parentheses to clarify the order of operators (not for a computer, but for people)

## Conditional Operator

- relation ? trueStatement : falseStatement;
- ex (total <= 3000.0) ? (total \*= 1.10) : (total \*= 1.05);
- shorter version: total \*= (total <= 3000.0) ? (1.10) : (1.05);
- The conditional often can appear in places where if can't go. 
- ex printf("I ate %d pear%s\n",numPear,(numPear > 1) ? ("s.") : ("."));

## -- and ++

- Don't think that a prefix and postfix always produce the same values

ex i = 2, j = 5 The following statements produce different values.
n = ++i * j; (Puts 3 in i and 15 in n)
n = i++ * j; (Puts 10 in n and 3 in i)

- A prefix and postfix are identical only when a single variable is involved

## While Loop

- while (condition) {block of one or more C statements;}
- do {block of one or more C statements;} while (condition)
- Make sure that body of the while or do...while loop changes something in the condition, or the loop will repeat forever
- Don't put a semicolon after the while condition's closing parenthesis or an infinite loop will occur

## For Loop

- for (startExpression; testExpression; countExpression) {block of one or more C statements;}
- Use a nested loop if you want to loop a certain number of times
