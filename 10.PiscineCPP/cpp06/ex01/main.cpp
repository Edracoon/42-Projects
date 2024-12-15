#include <iostream>

typedef	struct	Data
{

	int	i;
	int	j;

}	Data;

uintptr_t	serialize(Data* ptr)
{
	std::cout << "serialize : data* ptr = " << ptr << std::endl;
	return ( reinterpret_cast<uintptr_t>(ptr) );
}

Data*		deserialize(uintptr_t raw)
{
	std::cout << "deserialize : raw = " << raw << std::endl;
	return ( reinterpret_cast<Data *>(raw) );
}

int	main( void )
{
	Data*	data = new Data;
	data->i = 10;
	data->j = 15;

	Data		*converted;
	uintptr_t	uintconvert;

	std::cout << "addr data = " << data << std::endl;
	uintconvert = serialize(data);			// Stocker l'adresse de data dans mon uint;
	converted = deserialize(uintconvert);	// Cast de l'uint en data;
	std::cout << "addr converted = " << converted <<std::endl;
	std::cout << "converted->i = " << converted->i << std::endl;
	std::cout << "converted->j = " << converted->j << std::endl;

	// data et converted ont la meme addresse :
	data->i = 5;
	std::cout << "converted->i = " << converted->i << std::endl;
}
