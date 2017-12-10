# Pronoun Neutralizer
A program that replaces masculine pronouns with gender-neutral pronouns.

### Synopsis
This program is used to train the user to use less sexist language by suggesting alternative versions
of sentences given by the user.

For example, it will replace **"he"** by **"she or he"** and **"his"** by **"her(s)"**.

## Setup
1. Download and install [Git](https://git-scm.com/downloads), if you don't already have it.

2. Open terminal and run the git clone command:

   ```
   $ git clone https://github.com/cramaechi/pronoun-neutralizer.git
   ```
    or [download as ZIP](https://github.com/cramaechi/pronoun-neutralizer/archive/master.zip).

3. Go to the project folder:

   ```
   $ cd pronoun-neutralizer
   ```

4. Compile:

   ```
   $ make
   ```
   
## Usage
Run:

```
$ ./pronoun_neutralizer
```

Sample Output:
```
Enter a sentence: See an advisor, talk to him, and listen to him. He is wise.                                         
                                                                                                                      
Gender neutralized sentence: See an advisor, talk to her or him, and listen to her or him. She or he is wise.                                      
                                                                                                                      
Would like to enter input more text (y/n)?  y                                                                         
                                                                                                                      
                                                                                                                      
Enter a sentence: Is a doctor available now? I want to know if he can diagnose what this strange illness is.          
                                                                                                                      
Gender neutralized sentence: Is a doctor available now? I want to know if she or he can diagnose what this strange illness is.                     
                                                                                                                      
Would like to enter input more text (y/n)?  n 
```
