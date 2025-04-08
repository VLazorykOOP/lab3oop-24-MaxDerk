#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;

typedef complex<float> ComplexFloat;
class ComplexVector
{
    vector<ComplexFloat> v;
public:
    ComplexVector() = default;
    ComplexVector(int n) : v(n, ComplexFloat(0.0f, 0.0f))
    {
        if (n <= 0) cout << "Vec --> 0\n";
    }
    ComplexVector(int n, const ComplexFloat& val) : v(n, val)
    {
        if (n <= 0) cout << "Vec --> 0\n";
    }
    ComplexVector(const vector<ComplexFloat>& arr) : v(arr)
    {
        if (arr.empty()) cout << "Vec --> 0\n";
    }
    ComplexVector(const ComplexVector& other) = default;
    ComplexVector& operator=(const ComplexVector& other) = default;
    ~ComplexVector()
    {
        cout << "del vec\n";
    }
    void Input()
    {
        int n;
        cout << "Input size Vec: ";
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; ++i)
        {
            float re, im;
            cout << "v[" << i << "] real imag: ";
            cin >> re >> im;
            v[i] = ComplexFloat(re, im);
        }
    }
    void Output() const
    {
        for (size_t i = 0; i < v.size(); ++i)
        {
            cout << "v[" << i << "] " << v[i] << '\n';
        }
    }
    ComplexVector Add(const ComplexVector& b) const
    {
        int minSize = min(v.size(), b.v.size());
        ComplexVector result(minSize);
        for (int i = 0; i < minSize; ++i)
        {
            result.v[i] = v[i] + b.v[i];
        }
        return result;
    }
    ComplexVector Subtract(const ComplexVector& b) const
    {
        int minSize = min(v.size(), b.v.size());
        ComplexVector result(minSize);
        for (int i = 0; i < minSize; ++i) {
            result.v[i] = v[i] - b.v[i];
        }
        return result;
    }
    ComplexVector MultiplyByLong(long scalar) const
    {
        ComplexVector result(v.size());
        for (size_t i = 0; i < v.size(); ++i)
        {
            float re = v[i].real() * scalar;
            float im = v[i].imag() * scalar;
            result.v[i] = ComplexFloat(re, im);
        }
        return result;
    }
    ComplexFloat GetElement(int index) const
    {
        if (index >= 0 && index < v.size())
        {
            return v[index];
        } else
        {
            cout << "Invalid index" << endl;
            return ComplexFloat(0.0f, 0.0f);
        }
    }
    void SetElement(int index, const ComplexFloat& value = ComplexFloat(0.0f, 0.0f))
    {
        if (index >= 0 && index < v.size())
        {
            v[index] = value;
        } else
        {
            cout << "Invalid index" << endl;
        }
   }
    bool IsGreaterThan(const ComplexFloat& other) const
    {
        return abs(v[0]) > abs(other);
    }
    bool IsLessThan(const ComplexFloat& other) const
    {
        return abs(v[0]) < abs(other);
    }
    bool IsEqualTo(const ComplexFloat& other) const
    { 
        return abs(v[0]) == abs(other);
    }
};
int main()
{
    ComplexFloat a, b, c;
    float a1, a2, re, im;
    cout << "Input a: ";
    cin >> a1 >> a2;
    a = ComplexFloat(a1, a2);
    cout << "a: " << a << endl;
    cout << "Input b: ";
    cin >> re >> im;
    b = ComplexFloat(re, im);
    cout << "b: " << b << endl;
    c = a + b;
    cout << "a + b = " << c << endl;
    ComplexVector VecObj, VecObj1(10);
    cout << "VecObj:\n";
    VecObj.Output();
    cout << "VecObj1:\n";
    VecObj1.Output();
    cout << "Input a new complex float:\n";
    cin >> re >> im;
    a = ComplexFloat(re, im);
    ComplexVector VecObj2(10, a);
    VecObj2.Output();
    VecObj.Input();
    cout << "VecObj after input:\n";
    VecObj.Output();
    VecObj1 = VecObj.Add(VecObj2);
    cout << "VecObj after addition:\n";
    VecObj1.Output();
    ComplexVector VecObj3 = VecObj.Subtract(VecObj2);
    cout << "VecObj after subtraction:\n";
    VecObj3.Output();
    long scalar;
    cout << "Enter a multiplyer: ";
    cin >> scalar;
    ComplexVector VecObj4 = VecObj.MultiplyByLong(scalar);
    cout << "VecObj after multiplying:\n";
    VecObj4.Output();

    cout << "Comparing a and b:\n";
    if (VecObj.IsGreaterThan(b))
        cout << "a > b\n";
    else if (VecObj.IsLessThan(b))
        cout << "a < b\n";
    else
        cout << "a = b\n";
    int index;
    cout << "Enter index to get element from VecObj: ";
    cin >> index;
    ComplexFloat elem = VecObj.GetElement(index);
    cout << "Element at index " << index << ": " << elem << endl;
    cout << "Enter index to set element in VecObj: ";
    cin >> index;
    cout << "Enter values for the element: ";
    cin >> re >> im;
    VecObj.SetElement(index, ComplexFloat(re, im));
    cout << "VecObj after setting new element:\n";
    VecObj.Output();
    return 0;
}