cmake_minimum_required(VERSION 3.10)
project(IPTVVita)

# Crediti DraxTube
set(VITA_APP_NAME "IPTV Vita DraxTube")
set(VITA_TITLEID "DRAXT0001")

# Percorso dei sorgenti
set(SOURCES src/main.c)

if(NOT DEFINED ENV{VITASDK})
    message(FATAL_ERROR "VITASDK non trovato!")
endif()

add_executable(IPTVVita ${SOURCES})

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

# Se non hai l'icona, il toolchain userà quella di default se possibile
# Ma ti consiglio di mettere un file png a caso rinominato in icon0.png in sce_sys/
vita_setup_vpk(IPTVVita 
    ${VITA_TITLEID} 
    ${VITA_APP_NAME}
)
