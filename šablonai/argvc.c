int  // Specifies that type of variable the function returns.
     // main() must return an integer
main ( int argc, char **argv ) {
     for(int i = 0; i < argc; ++i)
        printf("%s", argv[i]);
     return 0; // Indicates that everything went well.
}
