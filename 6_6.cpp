#include <iostream>
#include <vector>
#include <complex>

using namespace std;


template <typename T>
class Polynomial {
private:
    vector<T> coefficients;
public:
    
    Polynomial() : coefficients(1, T(0)) {}

    
    Polynomial(const vector<T>& coeffs) : coefficients(coeffs) {}

    
    Polynomial operator+(const Polynomial& other) const {
        size_t maxSize = max(coefficients.size(), other.coefficients.size());
        vector<T> result(maxSize, T(0));

        for (size_t i = 0; i < maxSize; ++i) {
            if (i < coefficients.size()) result[i] += coefficients[i];
            if (i < other.coefficients.size()) result[i] += other.coefficients[i];
        }
        return Polynomial(result);
    }

   
    Polynomial operator*(const T& scalar) const {
        vector<T> result(coefficients.size());
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] = coefficients[i] * scalar;
        }
        return Polynomial(result);
    }


    T evaluate(const T& x) const {
        T result = T(0);
        T power = T(1);
        for (const T& coeff : coefficients) {
            result += coeff * power;
            power *= x;
        }
        return result;
    }

 
    void print() const {
        for (size_t i = 0; i < coefficients.size(); ++i) {
            cout << coefficients[i] << "x^" << i;
            if (i < coefficients.size() - 1) cout << " + ";
        }
        cout << endl;
    }
};
