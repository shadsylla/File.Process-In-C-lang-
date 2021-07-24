#include <stdio.h>


struct clientData {
   int acctNum;
   char lastName[ 15 ];
   char firstName[ 10 ];
   double balance;   /* acount balance */
}; /* client data */


int main()
{
  FILE *cfPtr; /*credit.dat file pointer*/

  /* create a clientData with default information */
  struct clientData client = { 0, "", "", 0.0 };

  /*fopen opens the file; exits if file cannot be opened */
  if ( (cfPtr = fopen ("credit.dat", "rb+") ) == NULL )
  {
    printf(("File won't open \n"));
  }/* end if that communicates with the user */
  else {
    printf(" Enter account number");
    " ( 1 to 100, 0 to end input )\n? " );
    scanf( "%d", &client.acctNum );

    /*user eneters info, which is copied into file*/
    while ( client.acctNum != 0 )
    {
      printf( "Enter lastname, firstname and balance\n? " );

      /*set record lastName, first name and balance */
      fscanf( stdin, "%s%s%lf", client.lastName,
         client.firstName, &client.balance );
      /* seek position in file to user-specified record */
      fseek( cfPtr, ( client.acctNum - 1 ) *
      sizeof( struct clientData ), SEEK_SET );

      /*write user-sepcified information in file*/
      fwrite( &client, sizeof( struct clientData ), 1, cfPtr );

      /* enable user to input another account number */
      printf("Enter account number\n? " );
      scanf( "%d", &client.acctNum );

    } /* end while */

  fclose( cfPtr ); /* fclose closes the file*/

} /* end els */
  return 0;
}
