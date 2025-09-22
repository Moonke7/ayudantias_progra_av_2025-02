#include <iostream>
using namespace std;

// ------------------ Laboratorio --------------------
class Libro
{
private:
    string titulo;
    string autor;
    string editorial;
    string genero;
    int fecha_publicacion;

public:
    Libro(string _titulo, string _autor, string _editorial, string _genero, int _fecha_publicacion)
    {
        titulo = _titulo;
        autor = _autor;
        editorial = _editorial;
        genero = _genero;
        fecha_publicacion = _fecha_publicacion;
    }

    // getters
    string getTitulo()
    {
        return titulo;
    }
    string getAutor()
    {
        return autor;
    }
    string getEditorial()
    {
        return editorial;
    }
    int getFechaPublicacion()
    {
        return fecha_publicacion;
    }
    string getGenero()
    {
        return genero;
    }

    // setters
    void setTitulo(string _titulo)
    {
        titulo = _titulo;
    }
    void setAutor(string _autor)
    {
        autor = _autor;
    }
    void setEditorial(string _editorial)
    {
        editorial = _editorial;
    }
    void setFechaPublicacion(int _fecha_publicacion)
    {
        fecha_publicacion = _fecha_publicacion;
    }
    void setGenero(string _genero)
    {
        genero = _genero;
    }
    // metodos

    void mostrarInfo()
    {
        cout << "Informacion del Libro:" << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Editorial: " << editorial << endl;
        cout << "Fecha de Publicacion: " << fecha_publicacion << endl;
        cout << "Genero: " << genero << endl;
        cout << endl;
    }
};

class Biblioteca
{
private:
    string nombre;
    int cantidad_libros;
    Libro *libros[10];

public:
    Biblioteca(string _nombre)
    {
        nombre = _nombre;
        cantidad_libros = 0;
        for (int i = 0; i < 10; i++)
        {
            libros[i] = NULL;
        }
    }

    // metofos
    void agregarLibro(Libro *libro)
    {
        for (int i = 0; i < 10; i++)
        {
            if (libros[i] == NULL)
            {
                libros[i] = libro;
                cantidad_libros++;
                return;
            }
        }

        cout << "No se pueden agregar mas libros" << endl;
    }

    void mostrarLibros()
    {
        cout << "Libros en la Biblioteca " << nombre << ":" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (libros[i] != NULL)
            {
                libros[i]->mostrarInfo();
            }
        }
    }

    void buscarPorTitulo(string _titulo)
    {
        cout << "Buscando libro con titulo: " << _titulo << endl;
        for (int i = 0; i < 10; i++)
        {
            if (libros[i] != NULL && libros[i]->getTitulo() == _titulo)
            {
                cout << "Libro encontrado:" << endl;
                libros[i]->mostrarInfo();
                return;
            }
        }
        cout << "Libro no encontrado" << endl;
        cout << endl;
    }

    void filtrarPorAño()
    {
        cout << "Filtrando libros publicados entre 2010 y 2020:" << endl;

        bool libroEncontrado = false;

        for (int i = 0; i < 10; i++)
        {
            if (libros[i] != NULL)
            {
                int año = libros[i]->getFechaPublicacion();
                if (año >= 2010 && año <= 2020)
                {
                    libros[i]->mostrarInfo();
                    libroEncontrado = true;
                }
            }
        }

        if (!libroEncontrado)
        {
            cout << "No se encontraron libros en el rango de años especificado." << endl;
        }
    }
};

// ------------------- Control ----------------------
class Dados
{
public:
    int LanzarDado()
    {
        return rand() % 6 + 1;
    }
};

class C21
{
private:
    int juegosGanados = 0;

public:
    bool jugar()
    {
        string respuesta;
        int suma = 0;
        Dados *dado = new Dados();

        do
        {
            cout << "¿Desea lanzar el dado? (si/no): ";
            cin >> respuesta;
            if (respuesta == "si")
            {
                int valor = dado->LanzarDado();
                suma += valor;
                cout << "Valor del dado: " << valor << endl;
                cout << "Suma actual: " << suma << endl;

                if (suma > 21)
                {
                    cout << "¡Has perdido! La suma excede 21." << endl;
                    return false;
                }
                else if (suma == 21)
                {
                    cout << "¡Felicidades! ¡Has ganado!" << endl;
                    juegosGanados++;
                    return true;
                }
            }
            else
            {
                cout << "Juego terminado. Suma final: " << suma << endl;
                if (suma < 21)
                {
                    cout << "No alcanzaste 21. Has perdido." << endl;
                }
                return false;
            }
        } while (respuesta == "si");

        return false;
    }

    int variosJuegos(int n)
    {
        int juegos_ganados = 0;

        for (int i = 0; i < n; i++)
        {
            if (jugar())
            {
                juegos_ganados++;
            }
        }
        return juegos_ganados;
    }
};

// -------------------- Ejercicio solemne 1 --------------------
class GastoDelMes
{
private:
    int vestuario;
    int alimentacion;
    int movilizacion;
    int ocio;
    int presupuestoMensual;

public:
    GastoDelMes(int _presupuesto)
    {
        vestuario = 0;
        alimentacion = 0;
        movilizacion = 0;
        ocio = 0;
        presupuestoMensual = _presupuesto;
    }

    void agregarGasto(int _vestuario, int _alimentacion, int _movilizacion, int _ocio)
    {
        vestuario += _vestuario;
        alimentacion += _alimentacion;
        movilizacion += _movilizacion;
        ocio += _ocio;
    }

    void imprimirResumen()
    {
        int suma = vestuario + alimentacion + movilizacion + ocio;
        cout << "-- Resumen de Gastos del Mes --" << endl;
        cout << "En vestuario se ha gastado: " << vestuario << ", lo que corresponde al " << (vestuario * 100) / suma << "%" << endl;
        cout << "En alimentacion se ha gastado: " << alimentacion << ", lo que corresponde al " << (alimentacion * 100) / suma << "%" << endl;
        cout << "En movilizacion se ha gastado: " << movilizacion << ", lo que corresponde al " << (movilizacion * 100) / suma << "%" << endl;
        cout << "En ocio se ha gastado: " << ocio << ", lo que corresponde al " << (ocio * 100) / suma << "%" << endl;
        cout << "El gasto total es: " << suma;
        if (suma > presupuestoMensual)
        {
            cout << ", por lo que se ha excedido el presupuesto mensual de " << presupuestoMensual << endl;
        }
        else
        {
            cout << ", por lo que no se ha excedido el presupuesto mensual de " << presupuestoMensual << endl;
        }
    }
};

class Atleta
{
private:
    string nombreAtleta, pais;
    float tiempoAntesFinal, tiempoFinal;

public:
    Atleta(string _nombreAtleta, string _pais, float _tiempoAntes)
    {
        nombreAtleta = _nombreAtleta;
        pais = _pais;
        tiempoAntesFinal = _tiempoAntes;
        tiempoFinal = 0;
    }

    void registrarTiempoFinal(float tiempo)
    {
        tiempoFinal = tiempo;
    }

    void imprimir()
    {
        cout << "---------------- Info del atleta ---------------" << endl;
        cout << "Nombre: " << nombreAtleta << endl;
        cout << "Pais: " << pais << endl;
        cout << "Mejor tiempo antes de final: " << tiempoAntesFinal << endl;

        if (tiempoFinal != 0)
        {
            // cout << "Tiempo en la final: "<< tiempoFinal << endl;
            cout << "Porcentaje respecto a su mejor tiempo anterior: " << (tiempoFinal * 100) / tiempoAntesFinal << endl;
        }
    }

    float getTiempoFinal()
    {
        return tiempoFinal;
    }

    string getNombre()
    {
        return nombreAtleta;
    }
};

class Carrera
{
private:
    Atleta *atletas[8];

public:
    Carrera()
    {
        for (int i = 0; i < 8; i++)
        {
            atletas[i] = NULL;
        }
    }

    void agregarAtleta(Atleta *atleta)
    {
        for (int i = 0; i < 8; i++)
        {
            if (atletas[i] == NULL)
            {
                atletas[i] = atleta;
                return;
            }
        }

        cout << "No hay espacio disponible" << endl;
    }

    void imprimirParticipantes()
    {
        for (int i = 0; i < 8; i++)
        {
            if (atletas[i] != NULL)
            {
                atletas[i]->imprimir();
            }
        }
    }

    string muestraGanador()
    {
        float mejorTiempo = 99999;

        for (int i = 0; i < 8; i++)
        {
            if (atletas[i] != NULL)
            {
                if (atletas[i]->getTiempoFinal() < mejorTiempo && atletas[i]->getTiempoFinal() != 0)
                {
                    mejorTiempo = atletas[i]->getTiempoFinal();
                }
            }
        }

        for (int i = 0; i < 8; i++){
            if (atletas[i] != NULL){
                if (atletas[i]->getTiempoFinal() == mejorTiempo){
                    return atletas[i]->getNombre();
                }
            }
        }

        return "Carrera aún no realizada";
    }
};

// ------------------ Ejercicio 3 ---------------------
class Volcan{
    private:
        string nombre;
        float altitud;
    public:
        void imprimir(){
            cout << nombre <<endl;
            cout << altitud << endl;
        }
};

class Sernageomin{
    private:
        Volcan *volcanes[20];
    
    public:
        Sernageomin(){
            for (int i = 0; i < 20; i++){
                volcanes[i] = NULL;
            }
        }

        void agregarVolcanes(Volcan *volcan){
            for (int i = 0; i < 20; i++){
                if(volcanes[i] == NULL){
                    volcanes[i] = volcan;
                    return;
                }
            }

            cout << "El registro de volcanes ta lleno" << endl;
        }
};


// ----------------- Ejercicio 5 -----------------
class Depto{
    private:
        int numeroDepto;
        string nombreDueño;
        string rut;
        int m2Depto, m2Edificio;
        int montoGastoComun;
        int fecha;

    public:
        Depto(int _numeroDepto, string _nombreDueño, string _rut, int _m2Depto, int _m2Edicio, int _fecha){
            numeroDepto = _numeroDepto;
            nombreDueño = _nombreDueño;
            rut = _rut;
            m2Depto = _m2Depto;
            m2Edificio = _m2Edicio;
            fecha = _fecha;
            montoGastoComun = 0;
        }

        int getNumeroDepto(){
            return numeroDepto;
        }
        string getNombreDueño(){
            return nombreDueño;
        }
        string getRut(){
            return rut;
        }
        int getM2Depto(){
            return m2Depto;
        }
        int getM2Edificio(){
            return m2Edificio;
        }
        int getMontoGastoComun(){
            return montoGastoComun;
        }
        int getFecha(){
            return fecha;
        }

        void setNumeroDepto(int _numeroDepto){
            numeroDepto = _numeroDepto;
        }
        void setNombreDueño(string _nombreDueño){
            nombreDueño = _nombreDueño;
        }
        void setRut(string _rut){
            rut = _rut;
        }
        void setM2Depto(int _m2Depto){
            m2Depto = _m2Depto;
        }
        void setM2Edificio(int _m2Edificio){
            m2Edificio = _m2Edificio;
        }
        void setMontoGastoComun(int _montoGastoComun){
            montoGastoComun = _montoGastoComun;
        }
        void setFecha(int _fecha){
            fecha = _fecha;
        }

        int CalcularGastoComun(int gastoMes){
            int porcentaje = (m2Depto * 100) / m2Edificio;
            int nuevoGastoComun = porcentaje * gastoMes;

            montoGastoComun = nuevoGastoComun;
            return nuevoGastoComun;
        }

        bool verMoroso(int _nuevaFecha){
            if (fecha < _nuevaFecha){
                return true;
            } else{
                return false;
            }
        }
};

int main()
{
    /* Biblioteca biblioteca("Biblioteca Central");

    Libro* libro1 = new Libro("a_titulo", "a_autor", "a_editorial", "a_genero", 2000);
    Libro* libro2 = new Libro("b_titulo", "b_autor", "b_editorial", "b_genero", 2018);
    Libro* libro3 = new Libro("c_titulo", "c_autor", "c_editorial", "c_genero", 2015);

    biblioteca.agregarLibro(libro1);
    biblioteca.agregarLibro(libro2);
    biblioteca.agregarLibro(libro3);

    biblioteca.mostrarLibros();

    biblioteca.buscarPorTitulo("c_titulo");
    biblioteca.buscarPorTitulo("a_titulo");
    biblioteca.buscarPorTitulo("x_titulo");

    biblioteca.filtrarPorAño(); */

    Atleta *at1 = new Atleta("chile", "juan", 90);

    return 0;
}