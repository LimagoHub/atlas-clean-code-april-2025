#include <iostream>
#include <climits>
#include <chrono>
#include <vector>
#include <memory>
#include <algorithm>
#include <thread>



int main() {


    /*
     *  Aufgabe: Schreibt eine Klasse mit einer CreateAndFillMethode-> sharedPoint<vector> (Liefert einen MitWerten befuellten Vector)
     *
     *  (Teilaufgabe Zeitmessung für die Durchführung mit 1 bis n threads)
     *
     */

    const size_t availableProcessors = std::thread::hardware_concurrency();

    std::cout << availableProcessors << "\n";

    const size_t collection_size = INT32_MAX / 2;

    auto feld =  std::make_shared<std::vector<int>>(collection_size);

    //feld->reserve(collection_size);

    std::cout << "Running....\n";
    auto start_ = std::chrono::high_resolution_clock ::now();

    for (int i = 0; i < collection_size; ++i) {
        feld->at(i) = rand();
    }

    auto end_ = std::chrono::high_resolution_clock ::now();

    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_ - start_).count()  << "\n";


    for (int i = 1; i <= availableProcessors + 1 ; ++i) {
        // Messungen
    }
    return 0;
}
