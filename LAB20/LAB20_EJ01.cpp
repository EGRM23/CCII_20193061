{
	//Declaramos un puntero de tipo double y lo inicializamos con valor 1.0
	double* d = new double(1.0);
	
	//Declaramos un puntero de tipo Point y lo inicializamos con 1,0 y 2.0
	Point* pt = new Point(1.0, 2.0);
	
	//Cambiamos el valor del puntero d a 2.00
	*d = 2.0;
	
	//Cambiamos el valor de X mediante un método de la clase point, usamos el
	//valor al que apunta el puntero
	(*pt).X(3.0);
	
	//Cambiamos el valor de Y mediante un método de la clase point, usamos el
	//valor al que apunta el puntero
	(*pt).Y(3.0);
	
	//Aquí también cambiamos el valor de X, pero usamos el puntero directamente
	//con ->
	pt->X(3.0);
	
	//Aquí también cambiamos el valor de Y, pero usamos el puntero directamente
	//con ->
	pt->Y(3.0);
	
	//Eliminamos los punteros creados
	delete d;
	delete pt;
}

