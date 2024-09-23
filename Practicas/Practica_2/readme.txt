Editor de codigo utilizado : Visual Studio Code

Pasos para compilar el proyecto en VSCode (Windows/Linux):

 Windows:
1. Tener la carpeta C:/SFML/bin en el Path de las variables de entorno
2. Configurar includePath en el c_cpp_properties.json que se encuentra en el directorio .vscode
(En mi caso, es C:\\SFML\\include)
3. Compilar con el siguiente comando:
        g++ -o app main.cpp src/Car.cpp src/Gui.cpp -IC:/SFML/include -LC:/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system -O2 -march=native -flto
4. Ejecutar el app.exe generado

 Linux (Mi sistema: Fedora 40):
1. Instalar SML con los siguientes comandos (Paquete desarrollo y componentes):
        sudo dnf install SFML-devel
        sudo dnf install SFML-graphics-devel SFML-window-devel SFML-audio-devel
2. Ejecutar el archivo build.bash que se encuentra en la raiz del proyecto.
    Comando:
        bash build.bash