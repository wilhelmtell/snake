#include "score_control.hh"
#include <memory>
#include <utility>
#include "event_dispatch.hh"
#include "abstract_factory.hh"
#include "score_output.hh"
#include "width.hh"
#include "height.hh"
#include "point.hh"
#include "rectangle.hh"
#include <boost/lexical_cast.hpp>

namespace snk {
score_control::score_control(event_dispatch* dispatch,
                             abstract_factory* factory)
: score_control{dispatch, factory, factory->make_score_output()} {}

score_control::score_control(event_dispatch* dispatch,
                             abstract_factory* /*factory*/,
                             std::unique_ptr<score_output> out)
: out{std::move(out)}, value{0} {
  dispatch->on_restart([&]() { on_restart(); });
  dispatch->on_berry_eaten([&](auto const& p) { on_berry_eaten(p); });
}

void score_control::update() {}

void score_control::draw() const {
  out->draw_text(
    boost::lexical_cast<std::string>(value), 0x70, 0x90, 0x00, 0xff);
}

void score_control::on_berry_eaten(point const& /*position*/) { ++value; }

void score_control::on_restart() { value = 0; }
}
