#include "register_types.h"

#include "nodes/gdexample.h"
#include "nodes/GridWorldNode.h"
#include "nodes/LineWorldNode.h"
#include "nodes/2RoundRPSNode.h"
#include "nodes/MontyHallNode.h"
#include "nodes/SecretEnv0Node.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_example_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }

    GDREGISTER_CLASS(GDExample);
    GDREGISTER_CLASS(GridWorldNode);
    GDREGISTER_CLASS(LineWorldNode);
    GDREGISTER_CLASS(RPSNode);
    GDREGISTER_CLASS(MontyHallNode);
    GDREGISTER_CLASS(SecretEnv0Node);
}

void uninitialize_example_module(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C" {
    // Initialization.
    GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization) {
        godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

        init_obj.register_initializer(initialize_example_module);
        init_obj.register_terminator(uninitialize_example_module);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}