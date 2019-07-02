//
// Created by sergio on 16/05/19.
//

#include "../../src/Model.h"
#include "../../src/Tensor.h"

#include <numeric>
#include <iomanip>

int main() {
    Model model("../model.pb");
    model.init();

    auto input_a = std::make_unique<Tensor>(model, "input_a");
    auto input_b = std::make_unique<Tensor>(model, "input_b");
    auto output  = std::make_unique<Tensor>(model, "result");

    std::vector<float> data(100);
    std::iota(data.begin(), data.end(), 0);

    input_a->set_data(data);
    input_b->set_data(data);

    model.run({input_a.get(), input_b.get()}, output.get());
    for (float f : output->get_data<float>()) {
        std::cout << f << " ";
    }
    std::cout << std::endl;

}
