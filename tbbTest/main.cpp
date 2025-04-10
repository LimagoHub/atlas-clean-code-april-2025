#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <memory>
#include <algorithm>
#include <thread>
#include <algorithm>
#include <execution>
#include "atlas/generator/impl/random/MersenneTwisterNumberGenerator.h"






int main() {
    const size_t collection_size = INT32_MAX / 2;



    auto feld =  std::make_shared<std::vector<int>>(collection_size);

    std::cout << "Running....\n";
    auto start_ = std::chrono::high_resolution_clock ::now();

    std::for_each( std::execution::par_unseq, feld->begin(), feld->end(),[](int &value){
        static thread_local auto generator = atlas::generator::MersenneTwisterNumberGenerator{};
        value = generator.next();

    });

    auto end_ = std::chrono::high_resolution_clock ::now();

    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count()  << "\n";
    return 0;
}

/*#include <tbb/parallel_for.h>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v(1000000, 1);

    tbb::parallel_for(size_t(0), v.size(), [&v](size_t i) {
        v[i] += 1;
    });

    std::cout << "First element: " << v[0] << std::endl;
    return 0;
}
*/
