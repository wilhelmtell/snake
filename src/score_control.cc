#include "score_control.hh"
#include <memory>
#include <utility>
#include "event_dispatch.hh"
#include "abstract_factory.hh"
#include "score_output.hh"

namespace snk {
score_control::score_control(event_dispatch* dispatch,
                             abstract_factory* factory)
: score_control{dispatch, factory, factory->make_score_output()} {}

score_control::score_control(event_dispatch* /*dispatch*/,
                             abstract_factory* /*factory*/,
                             std::unique_ptr<score_output> out)
: out{std::move(out)} {}
void score_control::update() {}

void score_control::draw() const {}
}
