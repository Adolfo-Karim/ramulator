import sys
import os

def main():
    for filepath in sys.argv[1:]:
        with open('mod_' + filepath, 'w') as new_file:
            with open(filepath, 'r') as f:
                for line in f:
                    tokens = line.split(' ')
                    if (tokens[0] == 'G'):
                        new_file.write(' '.join(tokens[1:]).strip() + ' G\n')
                    elif ("iteration" not in line):
                        new_file.write(line)

if __name__ == '__main__':
    main()
