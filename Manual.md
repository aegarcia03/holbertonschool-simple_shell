## **Simple Shell User Manual**
### **Introduction**

Welcome to the Simple Shell, a command-line interface that provides a powerful and flexible way to interact with your system. This manual will guide you through the basics of using the shell, including common commands, advanced features interface that allows you to interact with your system. This manual will guide you through the basics of using the shell and help you get started.

The Simple Shell is a versatile command-line interface that supports both interactive and non-interactive usage. This manual will guide you through the basics of using the shell in both modes.
### **Getting Started**

1. **Open the Terminal:** To open the shell, you can typically search for "Terminal" in your application menu or use a keyboard shortcut (e.g., `Ctrl+Alt+T` on Ubuntu).
2. **Enter Commands:** Once the terminal is open, you can execute the shell with typing ./hsh and press enter then you'll see a prompt (e.g., `$`). This is where you'll type your commands.
**Starting the Shell**

To start the shell, simply type `hsh` in your terminal prompt (assuming you're using a Linux-based system). You'll see a prompt
(`$`) indicating that you're ready to enter commands.

```bash
$
```

Pressing `Ctrl+D` will terminate the shell.
To exit the shell, type `exit` and press Enter or press CRTL + D

### **Interactive Mode**

In interactive mode, you interact with the shell directly, entering commands at a prompt.

1. **Accessing the Shell:** Open a terminal window to access the shell.
2. **Entering Commands:** Type commands at the prompt (e.g., `$`). The shell will execute the commands and display the output.
3. **Exiting the Shell:** Type `exit` to terminate the interactive session.
### **Example Usage**

```
$ ls
file1 file2
$ cd /tmp
$ pwd
/tmp
$ echo hello
hello
$ exit
```
### **Basic Commands**

* **Navigating Directories:**
  * `cd`: Changes the current directory. For example, `cd Documents` will move you to the "Documents" folder.
  * `pwd`: Displays the current working directory.
* **Listing Files and Directories:**
  * `ls`: Lists the contents of the current directory.
  * `ls -l`: Lists files with detailed information (permissions, size, owner, etc.).
* **Creating and Deleting Files:**
  * `touch filename`: Creates a new file named "filename".
  * `rm filename`: Deletes the file named "filename".
* **Executing Programs:**
  * Type the name of the program you want to run. For example, `gedit` will open a text editor.

Here are some basic commands to get you started:

### 1. Help

Display a list of available commands and their descriptions:

```bash
$ help
```

### 2. Exit

Exit the shell:

```bash
$ exit
```

### 3. cd

Change directory (move into a new directory):

```bash
$ cd [directory]
```

*   Replace `[directory]` with the path to the desired directory.

Example:
```bash
$ cd Documents/
```

### 4. ls

List files and directories in the current working directory:

```bash
$ ls
```

### 5. pwd

Display the current working directory:

```bash
$ pwd
```


### **Non-Interactive Mode**

In non-interactive mode, you provide commands as arguments to the shell executable.

1. **Running the Shell:** Open a terminal and type eg: `hsh < filename.sh`, where `filename.sh` is a script containing your commands.
2. **Executing Commands:** The shell will execute the commands in the script sequentially.
3. **Exiting the Shell:** The shell will exit automatically when it reaches the end of the script.

### **Combining Interactive and Non-Interactive Usage**

You can combine interactive and non-interactive usage by creating a script and running it from within an interactive shell session. This allows you to customize your shell environment and automate tasks.
### **Advanced Features**

* **Arguments:** Many commands can take arguments to modify their behaviour. For example, `ls -a` lists all files, including hidden ones.
* **Environment Variables:** Environment variables store information about your system. You can view them using the `env` command.
* **Pipes:** Pipes allow you to connect the output of one command to the input of another. For example, `ls | wc -l` counts the number of files in the current directory.
* **Redirection:** Redirection allows you to control the input and output of commands. For example, `command > output.txt` redirects the output of "command" to the file "output.txt".

### **Additional Features**

* **History:** The shell maintains a history of your commands, allowing you to recall and re-execute them using the up and down arrow keys.
* **Aliases:** You can create aliases for frequently used commands to simplify their usage. For example, `alias ll='ls -l'`.
* **Job Control:** The shell supports job control, allowing you to manage background processes and foreground jobs.
* **Customizations:** You can customize the shell's appearance and behavior using configuration files.

### **Troubleshooting**

* **Command Not Found:** If you receive an "command not found" error, ensure the command is installed and in your system's PATH.
* **Permission Errors:** If you encounter permission issues, try using `sudo` to run commands with elevated privileges.
* **Syntax Errors:** Check for typos or incorrect syntax in your commands.

### **Additional Resources**

* **Online Manuals:** Consult the official documentation for your Linux distribution for more in-depth information.
* **Community Forums:** Online forums and communities can provide valuable assistance and troubleshooting tips.

**Remember:** The Simple Shell is a powerful tool that can be tailored to your specific needs. Explore its features and capabilities to enhance your productivity and efficiency.
