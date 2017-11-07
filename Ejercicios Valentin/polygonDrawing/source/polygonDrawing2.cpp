#include <iostream>


/*
 * This program creates a Quadrilateral with the base and height that the user choices. Set base and height only in the imput.
 */

using namespace std;


class Polygon {

    protected :

        int base;

        int height;

        bool **figure;


    public :

        Polygon ( int base, int height ) : base ( base ), height ( height ) {


            figure = new bool* [height];


            for ( int i = 0; i < height; i++ ) {

                figure[i] = new bool [base];

            }


        }


        ~Polygon () {

            for ( int i = 0; i < height; i++ ) {

                delete [] figure [i];

            }

            delete [] figure;

        }

        void setBase ( int base ) {

            this->base = base;

        }


        void setHeight ( int height ) {

            this->height = height;

        }


        int getBase () const {

            return base;

        }


        int getHeight () const {

            return height;

        }


        void drawPolygon () const {

            for ( int i = 0; i < height; i++ ) {

                for ( int j = 0; j < base; j++ ) {

                    if ( figure [i][j] ) {

                        cout << "* ";

                    } else {

                        cout << "  ";

                    }

                }

                cout << endl;

            }


        }

};



class Quadrilateral : public Polygon {


    public :

       Quadrilateral ( int base, int height ) : Polygon ( base, height) {

           createQuadrilateral ();

       }


       void createQuadrilateral () {


           for ( int i = 0; i < height; i++ ) {

               for ( int j = 0; j < base; j++ ) {

                   figure [i][j] = false;

                   if ( i == 0 || ( i + 1 ) == height ) {

                       figure [i][j] = true;

                   }

                   if ( j == 0 || ( j + 1 ) == base ) {

                       figure [i][j] = true;

                   }

               }

           }


       }

};


int main() {

    int base, height = 0;


    cin >> base;

    cin >> height;

    if ( base == 0 || height == 0 ) cout << "Set base and height in this order in the imput to create the polygon." << endl;


    Quadrilateral figure1 ( base, height );

    figure1.drawPolygon ();



	return 0;

}
