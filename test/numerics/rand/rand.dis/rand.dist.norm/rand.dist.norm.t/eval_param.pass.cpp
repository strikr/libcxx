//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <random>

// template<class RealType = double>
// class student_t_distribution

// template<class _URNG> result_type operator()(_URNG& g, const param_type& parm);

#include <random>
#include <cassert>
#include <vector>
#include <numeric>

template <class T>
inline
T
sqr(T x)
{
    return x * x;
}

int main()
{
    {
        typedef std::student_t_distribution<> D;
        typedef D::param_type P;
        typedef std::minstd_rand G;
        G g;
        D d;
        P p(5.5);
        const int N = 1000000;
        std::vector<D::result_type> u;
        for (int i = 0; i < N; ++i)
            u.push_back(d(g, p));
        double mean = std::accumulate(u.begin(), u.end(), 0.0) / u.size();
        double var = 0;
        double skew = 0;
        double kurtosis = 0;
        for (int i = 0; i < u.size(); ++i)
        {
            double d = (u[i] - mean);
            double d2 = sqr(d);
            var += d2;
            skew += d * d2;
            kurtosis += d2 * d2;
        }
        var /= u.size();
        double dev = std::sqrt(var);
        skew /= u.size() * dev * var;
        kurtosis /= u.size() * var * var;
        kurtosis -= 3;
        double x_mean = 0;
        double x_var = p.n() / (p.n() - 2);
        double x_skew = 0;
        double x_kurtosis = 6 / (p.n() - 4);
        assert(std::abs(mean - x_mean) < 0.01);
        assert(std::abs(var - x_var) / x_var < 0.01);
        assert(std::abs(skew - x_skew) < 0.01);
        assert(std::abs(kurtosis - x_kurtosis) / x_kurtosis < 0.2);
    }
    {
        typedef std::student_t_distribution<> D;
        typedef D::param_type P;
        typedef std::minstd_rand G;
        G g;
        D d;
        P p(10);
        const int N = 1000000;
        std::vector<D::result_type> u;
        for (int i = 0; i < N; ++i)
            u.push_back(d(g, p));
        double mean = std::accumulate(u.begin(), u.end(), 0.0) / u.size();
        double var = 0;
        double skew = 0;
        double kurtosis = 0;
        for (int i = 0; i < u.size(); ++i)
        {
            double d = (u[i] - mean);
            double d2 = sqr(d);
            var += d2;
            skew += d * d2;
            kurtosis += d2 * d2;
        }
        var /= u.size();
        double dev = std::sqrt(var);
        skew /= u.size() * dev * var;
        kurtosis /= u.size() * var * var;
        kurtosis -= 3;
        double x_mean = 0;
        double x_var = p.n() / (p.n() - 2);
        double x_skew = 0;
        double x_kurtosis = 6 / (p.n() - 4);
        assert(std::abs(mean - x_mean) < 0.01);
        assert(std::abs(var - x_var) / x_var < 0.01);
        assert(std::abs(skew - x_skew) < 0.01);
        assert(std::abs(kurtosis - x_kurtosis) / x_kurtosis < 0.04);
    }
    {
        typedef std::student_t_distribution<> D;
        typedef D::param_type P;
        typedef std::minstd_rand G;
        G g;
        D d;
        P p(100);
        const int N = 1000000;
        std::vector<D::result_type> u;
        for (int i = 0; i < N; ++i)
            u.push_back(d(g, p));
        double mean = std::accumulate(u.begin(), u.end(), 0.0) / u.size();
        double var = 0;
        double skew = 0;
        double kurtosis = 0;
        for (int i = 0; i < u.size(); ++i)
        {
            double d = (u[i] - mean);
            double d2 = sqr(d);
            var += d2;
            skew += d * d2;
            kurtosis += d2 * d2;
        }
        var /= u.size();
        double dev = std::sqrt(var);
        skew /= u.size() * dev * var;
        kurtosis /= u.size() * var * var;
        kurtosis -= 3;
        double x_mean = 0;
        double x_var = p.n() / (p.n() - 2);
        double x_skew = 0;
        double x_kurtosis = 6 / (p.n() - 4);
        assert(std::abs(mean - x_mean) < 0.01);
        assert(std::abs(var - x_var) / x_var < 0.01);
        assert(std::abs(skew - x_skew) < 0.01);
        assert(std::abs(kurtosis - x_kurtosis) / x_kurtosis < 0.02);
    }
}
