
/* ENUMS
* With enums you can 'create your own' data type.
* It's a data type that you can define.
 */

enum month {January, February, March, April, May, June, July, August, September, October, November, December};
/* Represented by numbers. First name (january) in the list is 0. December is 11. */

enum month thisMonth;
thisMonth = September; /* Will have value 8 */

/* CHARS 
* Represents a single character.
* You can assign ASCII values to chars.
*/

char Aa = 'A';

/* Examples of bad practices.
char broiled;
broiled = 'T';  OK 
broiled = T;  Not OK. Thinks T is a variable. 
broiled = "T";  Also not OK. Thinks "T" is a string 
*/

/* Escape characters */
char x = '\n'; /* For example. There are lots */