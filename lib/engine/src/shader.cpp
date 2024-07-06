#include <smash.h>
#include <sh.h>

namespace smash
{
    void Shader::execute(ShaderAttributes& attributes, Canvas& canvas) const
    {
        shAccess::setShattr(attributes);
        shAccess::setCvs(canvas);
        shade();
    }
}