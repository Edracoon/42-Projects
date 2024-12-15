#ifndef SAMPLE_HPP
# define SAMPLE_HPP

# include <iostream>

class Sample
{
	private:
			int		_i;

	public:
			Sample( void );											//->| Constructeur par défaut.
			Sample(int n);											//->| Constructeur parametrique.
																	//	|-------------------------
																	//	| Constructeur par copie, 
			Sample( Sample const & src);							//->| prenant en parametre une instance de la classe, 
																	//	| pour realiser une copie de cette classe dans la nouvelle.
																	//	|-------------------------
			~Sample( void );										//->| Destructeur.
																	//->|-------------------------
			Sample& operator=(Sample const & rhs);					//-> Operateur d'assignateur '=' qui permettra d'assigner une classe à une autre.
};																	//  |-------------------------
																	//  |-------------------------
std::ofstream&	operator<<(std::ofstream & ofs, Sample const & rhs);//-> Operateur d'affichage de la classe, va permettre de redefinir std::cout << Sample << std::endl;

#endif