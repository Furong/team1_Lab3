//
//  scanner.c
//  Lab3
//
//  Created by Bryce Holton.
//  Copyright (c) 2014 Bryce Holton. All rights reserved.
//

#include <stdio.h>
#include "scanner.h"
#include "common.h"

/*******************
 Static functions needed for the scanner
 You need to design the proper parameter list and 
 return types for functions with ???.
 ******************/
<<<<<<< HEAD:TEAM1/scanner.c
static char* get_char(char*);
static char* skip_comment(char*);
static char* skip_blanks(char*);
static char* get_word(char*);
static char* get_number(char*);
static char* get_string(char*);
static char* get_special(char*);
static char* downshift_word(char*);
static BOOLEAN is_reserved_word(char*);
static char source_buffer[MAX_SOURCE_LINE_LENGTH];
static char* scanptr='\0';
static BOOLEAN state=TRUE;
=======
static ??? get_char(???);
static ??? skip_comment(???);
static ??? skip_blanks(???);
static ??? get_word(???);
static ??? get_number(???);
static ??? get_string(???);
static ??? get_special(???);
static ??? downshift_word(???);
static BOOLEAN is_reserved_word(???);
static char source_buffer[]
>>>>>>> 00f4b448b4181c2f0436ae779485b68bcbb45d65:cse220-lab3/scanner.c

typedef enum
{
    LETTER, DIGIT, QUOTE, SPECIAL, EOF_CODE,
}
CharCode;
CharCode type;

/*********************
 Static Variables for Scanner
 Must be initialized in the init_scanner function.
 *********************/
static FILE *src_file;
static char src_name[MAX_FILE_NAME_LENGTH];
static char todays_date[DATE_STRING_LENGTH];
static CharCode char_table[256];  // The character table

typedef struct
{
    char *string;
    TokenCode token_code;
}
RwStruct;

const RwStruct rw_table[9][10] = {
    {{"do",DO},{"if",IF},{"in",IN},{"of",OF},{"or",OR},{"to",TO},{NULL,0}}, //Reserved words of size 2
    {{"and",AND},{"div",DIV},{"end",END},{"for",FOR},{"mod",MOD},{"nil",NIL},{"not",NOT},{"set",SET},{"var",VAR},{NULL,0}}, //Reserved words of size 3
    {{"case",CASE},{"else",ELSE},{"file",FFILE},{"goto",GOTO},{"then",THEN},{"type",TYPE},{"with",WITH},{NULL,0}}, //Reserved words of size 4
    {{"array",ARRAY},{"begin",BEGIN},{"const",CONST},{"label",LABEL},{"until",UNTIL},{"while",WHILE},{NULL,0}},  //Reserved words of size 5
    {{"downto",DOWNTO}, {"packed",PACKED},{"record",RECORD}, {"repeat",REPEAT},{NULL,0}},  // Reserved words of size 6
    {{"program", PROGRAM},{NULL,0}}, // Reserved words of size 7
    {{"function", FUNCTION},{NULL,0}}, // Reserved words of size 8
    {{"procedure", PROCEDURE},{NULL,0}}  // Reserved words of size 9
};

void init_scanner(FILE *source_file, char source_name[], char date[])
{
    src_file = source_file;
    strcpy(src_name, source_name);
    strcpy(todays_date, date);
    
    /*******************
     initialize character table, this table is useful for identifying what type of character 
     we are looking at by setting our array up to be a copy the ascii table.  Since C thinks of 
     a char as like an int you can use ch in get_token as an index into the table.
     *******************/
    
}
BOOLEAN get_source_line(char source_buffer[])
{
    char print_buffer[MAX_SOURCE_LINE_LENGTH + 9];
//    char source_buffer[MAX_SOURCE_LINE_LENGTH];  //I've moved this to a function parameter.  Why did I do that?
    static int line_number = 0;
    
    if (fgets(source_buffer, MAX_SOURCE_LINE_LENGTH, src_file) != NULL)
    {
        ++line_number;
        sprintf(print_buffer, "%4d: %s", line_number, source_buffer);
        print_line(print_buffer, src_name, todays_date);
        return (TRUE);
    }
    else
    {
        return (FALSE);
    }
}
Token* get_token()
{
    char ch; //This can be the current character you are examining during scanning.
    char token_string[MAX_TOKEN_STRING_LENGTH]; //Store your token here as you build it.
    char *token_ptr =source_buffer; //write some code to point this to the beginning of token_string
    Token *mytoken;//I am missing the most important variable in the function, what is it?  Hint: what should I return?
    *mytoken=malloc(sizeof(Token));
    if(*scanptr='\0')
    	{
    	if( get_source_line)
    	state=TRUE;
    	scanptr=source_buffer;
    	}

    scanptr=skip_blanks(scanptr);
    scanptr=get_char(scanptr);
    if(type==LETTER)
    {
    	token_string=get_word(scanptr);
    	mytoken->LiteralType=REAL_LIT;

    }
    if(type== DIGIT)
    {
       token_string=get_number(scanptr);
       mytoken->LiteralType=INTEGER_LIT;
    }
    if(type== QUOTE)
    {
           token_string=get_string(scanptr);
           mytoken->LiteralType=STRING_LIT;
    }
    strcp(mytoken->token_string,token_string);
    mytoken->NextToken=scanptr++;


    //1.  Skip past all of the blanks
    //2.  figure out which case you are dealing with LETTER, DIGIT, QUOTE, EOF, or special, by examining ch
    //3.  Call the appropriate function to deal with the cases in 2.
    
    return mytoken; //What should be returned here?
}
<<<<<<< HEAD:TEAM1/scanner.c
static char* get_char(*chptr)
{


	if(*chptr>='0'&&*chptr<='9')
		type= DIGIT;
	else if((*chptr>='A'&&*chptr<='Z')||(*chptr>='a'&&*chptr<='z'))
		type=LETTER;
	else if(*chptr=='"')
		type=QUOTE;
	else
		type=SPECIAL;
	return chptr;
=======
static ??? get_char(char *p)
{
    if(
    {
     ch=EOF;
     return ch;
    }
    else
    {
     ch=*p;
     p=p++;//???????
     return ch;
    }
>>>>>>> 00f4b448b4181c2f0436ae779485b68bcbb45d65:cse220-lab3/scanner.c
    /*
     If at the end of the current line (how do you check for that?),
     we should call get source line.  If at the EOF (end of file) we should
     set the character ch to EOF and leave the function.
     */
    
    /*
     Write some code to set the character ch to the next character in the buffer
     */
}
<<<<<<< HEAD:TEAM1/scanner.c
static char* skip_blanks(*chptr)
=======
static ??? skip_blanks(char *p)
>>>>>>> 00f4b448b4181c2f0436ae779485b68bcbb45d65:cse220-lab3/scanner.c
{
	while(*chptr==" ")
		chptr++;
	return chptr;
    /*
     Write some code to skip past the blanks in the program and return a pointer
     to the first non blank character
     */
<<<<<<< HEAD:TEAM1/scanner.c
=======
     while(*p=='')
     p++;
     return p;
    
>>>>>>> 00f4b448b4181c2f0436ae779485b68bcbb45d65:cse220-lab3/scanner.c
}
    
static char* skip_comment(char *chptr)
{
	while(*chptr!='')
		chptr++;
	return chptr;

    /*
     Write some code to skip past the comments in the program and return a pointer
     to the first non blank character.  Watch out for the EOF character.
     */
}
static char* get_word(char *chptr)
{
	    char Letter[20];
		int i=0;
		for(i=0;*chptr!=' ';i++)
		{
			Letter[i]=*chptr;
			chptr++;
		}
		Letter[i+1]='\0';
		return Letter;

    /*
     Write some code to Extract the word
     */
    
    //Downshift the word, to make it lower case
    
    /*
     Write some code to Check if the word is a reserved word.
     if it is not a reserved word its an identifier.
     */
}
static char* get_number(char *chptr)
{
	        char Number[20];
	        int i=0;
			for(i=0;*chptr!=' ';i++)
			{
				Number[i]=*chptr;
				chptr++;
			}
			Number[i+1]='\0';
			return Number;
    /*
     Write some code to Extract the number and convert it to a literal number.
     */
}
static char* get_string(char *chptr)
{
	            char Str[50];
		        int i=0;
		        Str[0]='"';
		        chptr++;
				for(i=1;*chptr='"';i++)
				{
					Number[i]=*chptr;
					chptr++;
				}
				Number[i+1]='\0';
				return Str;
    /*
     Write some code to Extract the string
     */
}
static char* get_special(char *chptr)
{
	            char Spec[20];
		        int i=0;
				for(i=0;*chptr!=' ';i++)
				{
					Spec[i]=*chptr;
					chptr++;
				}
				Number[i+1]='\0';
				return Spec;

    /*
     Write some code to Extract the special token.  Most are single-character
     some are double-character.  Set the token appropriately.
     */
}
static char* downshift_word(char *chptr)
{
	char Low[20];
	int i=0;
	for(i=0;*chptr!='\0';i++)
	{
		if((*chptr>='A'&&*chptr<='Z'))
			*chptr+('a'-'A');
		chptr++;
	}
	return Low;
    /*
     Make all of the characters in the incoming word lower case.
     */
}
static BOOLEAN is_reserved_word(char*)
{

    /*
     Examine the reserved word table and determine if the function input is a reserved word.
     */
    return FALSE;
}
