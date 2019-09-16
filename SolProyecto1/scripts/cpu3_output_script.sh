red=`tput setaf 1`
green=`tput setaf 2`
reset=`tput sgr0`
exec gnome-terminal --geometry 70x7+750+390 -- bash -c "echo -e \"${red}Simulador del CPU 3\n${reset}\"; tail -f /home/ubuntucristian/Dropbox/12semestre/arqui_2/proyectos/SolProyecto1/output/cpu3_output" 
