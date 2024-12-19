#include"fileHandler.h"
static bool checkIfTxt(char *txt);
static FILE *openFile(char *txt);

static bool checkIfTxt(char *txt){

int length=strlen(txt);
int p=1,s=0;
bool isItAfterDot=false;

char *wordAfterDot=(char*)malloc(p*sizeof(char));
if(wordAfterDot==NULL){
    perror("Can't allocate");
    exit(-1);
}


for(int i=0;i<length;i++){

if(txt[i]=='.')
isItAfterDot=true;

else if(isItAfterDot){
    if(s==p){
        p++;
        char* temp=(char*)realloc(wordAfterDot,p*sizeof(char));
        if(temp==NULL){
    perror("Can't reallocate");
    exit(-1);
}
else{
    wordAfterDot=temp;
}
    }
wordAfterDot[s]=txt[i];
s++;
}
}

  // Make extra sapce for the '\0'
        p++;
        char* temp=(char*)realloc(wordAfterDot,p*sizeof(char));
        if(temp==NULL){
    perror("Can't reallocate");
    exit(-1);
}
else{
    wordAfterDot=temp;
}
wordAfterDot[s]='\0';
if(strcmp("txt",wordAfterDot)==0){
free(wordAfterDot);
return true;
}
free(wordAfterDot);
return false;
}


static FILE *openFile(char *txt){
  if(!checkIfTxt(txt)){
    printf("It is not a txt\n");
     exit(-1);
  }
FILE *read=fopen(txt,"r");
if(read==NULL){
    perror("can't open file");
    exit(-1);
}
return read;
}

void freeArray(int**pin,int sizeOfArray){
    if (pin == NULL) {
        return;
    }
    for(int j=0;j<sizeOfArray;j++)
        free(pin[j]);
    free(pin);
}



int **fill(char *txt,int *sizeOfArray){

FILE *read=openFile(txt);

int k=0,s=0,num=0,plithOfNumsInFile=0;

fscanf(read,"%d",&num);

*sizeOfArray=num;
int fullSizeOfArray=(*sizeOfArray) * (*sizeOfArray);
if(*sizeOfArray<=1){
    printf("The length of the array is not valid\n");
    exit(-1);
}

int **pin=(int**)malloc(*sizeOfArray*sizeof(int*));
for(int i=0;i<*sizeOfArray;i++)
pin[i]=(int*)malloc(*sizeOfArray*sizeof(int));


while(fscanf(read,"%d",&num)!=EOF){
plithOfNumsInFile++;

if(plithOfNumsInFile>fullSizeOfArray){
      printf("You have more numbers int the txt.Must be NXN\n");
      freeArray(pin,*sizeOfArray);
      fclose(read);
    exit(-1);
}

 if((num>0)||(num<-(*sizeOfArray))){
         printf("You have an invalid number\n");
         freeArray(pin,*sizeOfArray);
      fclose(read);
    exit(-1);
    }

    if(s==*sizeOfArray){
       k++;
       s=0;
    }
    

pin[k][s]=num;
s++;
}

if(plithOfNumsInFile<fullSizeOfArray){
    printf("You have less numbers int the txt.Must be NXN\n");
    freeArray(pin,*sizeOfArray);
      fclose(read);
    exit(-1);
}
  fclose(read);
  return pin;

}



#ifdef DEBUG_FILEHANDLER

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename.txt>\n", argv[0]);
        return 1;
    }

    // Size of the array (will be set by `fill`)
    int sizeOfArray;
    
    // Fill the array from the file specified in argv[1]
    int **array = fill(argv[1], &sizeOfArray);
    
    // Print the array
    printf("Array loaded from file %s:\n", argv[1]);
    for (int i = 0; i < sizeOfArray; i++) {
        for (int j = 0; j < sizeOfArray; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    // Free the dynamically allocated array
    freeArray(array, sizeOfArray);

    return 0;
}
#endif
