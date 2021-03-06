//
//  common.c
//  Lab3
//
//  Created by Bryce Holton.
//  Copyright (c) 2014 Bryce Holton. All rights reserved.
//

#ifndef CSE220_project2_common_h
#define CSE220_project2_common_h

#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include "scanner.h"
#define FORM_FEED_CHAR          '\f'
#define MAX_FILE_NAME_LENGTH    32
#define MAX_SOURCE_LINE_LENGTH  256
#define MAX_TOKEN_STRING_LENGTH MAX_SOURCE_LINE_LENGTH
#define MAX_PRINT_LINE_LENGTH   80
#define MAX_LINES_PER_PAGE      50
#define DATE_STRING_LENGTH      26

typedef enum
{
    FALSE, TRUE,
}
BOOLEAN;

/***************************
 Token Codes
 ***************************/
typedef enum
{
    NO_TOKEN, IDENTIFIER, NUMBER, STRING, UPARROW, STAR, LPAREN,
    RPAREN, MINUS, PLUS, EQUAL, LBRACKET,
    RBRACKET, COLON, SEMICOLON, LT, GT, COMMA, PERIOD, SLASH,
    COLONEQUAL, LE, GE, NE, DOTDOT, END_OF_FILE, ERROR, AND,
    ARRAY, BEGIN, CASE, CONST, DIV, DO, DOWNTO, ELSE, END, FFILE,
    FOR, FUNCTION, GOTO, IF, IN, LABEL, MOD, NIL, NOT, OF, OR, PACKED,
    PROCEDURE, PROGRAM, RECORD, REPEAT, SET, THEN, TO, TYPE, UNTIL,
    VAR, WHILE, WITH,
}
TokenCode;

/*****************************
 Literal Type
 *****************************/
typedef enum
{
    INTEGER_LIT, REAL_LIT, STRING_LIT,IS_RESERVED,
}
LiteralType;

/**************
 this is a valid Pascal token.  A token must have a literal type,
 a literal value, and a token code.  It also must have a link to 
 another token since this must be stored as a linked list.
 ***************/

typedef struct
{
<<<<<<< HEAD:TEAM1/common.h
	LiteralType type;
    char token_string[MAX_TOKEN_STRING_LENGTH];
    Token *NextToken;//Missing code goes here
=======
    //Missing code goes here
    LiteralType type;//define a literal type *
    char token_string[MAX_Token_STRING_LENGTH];//I'm not sure about this,to store the literal value?
    Token *NextToken;// a token pointer to next token
    
>>>>>>> 00f4b448b4181c2f0436ae779485b68bcbb45d65:cse220-lab3/common.h
}
Token;

#endif
