cmake_minimum_required(VERSION 3.10)

# Imposta il VITASDK se non definito (per sicurezza)
if(NOT DEFINED ENV{VITASDK})
    message(FATAL_ERROR "VITASDK environment variable not set")
endif()
set(VITASDK $ENV{VITASDK})

# Carica i moduli Vita PRIMA del progetto
list(APPEND CMAKE_MODULE_PATH "${VITASDK}/share/cmake/Modules")
include("${VITASDK}/share/vita.cmake")

project(IPTVVita)

# Crediti DraxTube
set(VITA_APP_NAME "IPTV Vita DraxTube")
set(VITA_TITLEID "DRAXT0001")

# Sorgenti
add_executable(IPTVVita src/main.c)

# Librerie necessarie
target_link_libraries(IPTVVita 
    SceNet_stub 
    SceNetCtl_stub 
    SceSsl_stub 
    SceHttp_stub
    SceVideoPlayer_stub
    SceDisplay_stub
    SceGxm_stub
    SceSysmodule_stub
    SceLibKernel_stub
)

# Creazione VPK
vita_setup_vpk(IPTVVita 
    ${VITA_TITLEID} 
    ${VITA_APP_NAME}
)
