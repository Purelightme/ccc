cmake_minimum_required(VERSION 3.15)
project(http_service C)

set(CMAKE_C_STANDARD 11)

include_directories(lib/facil)
include_directories(lib/facil/cli)
include_directories(lib/facil/fiobj)
include_directories(lib/facil/http)
include_directories(lib/facil/http/parsers)
include_directories(lib/facil/legacy)
include_directories(lib/facil/redis)
include_directories(lib/facil/tls)
include_directories(src)

add_executable(http_service
    lib/facil/cli/fio_cli.c
    lib/facil/cli/fio_cli.h
    lib/facil/fiobj/fio_json_parser.h
    lib/facil/fiobj/fio_siphash.c
    lib/facil/fiobj/fio_siphash.h
    lib/facil/fiobj/fio_tmpfile.h
    lib/facil/fiobj/fiobj.h
    lib/facil/fiobj/fiobj4fio.h
    lib/facil/fiobj/fiobj_ary.c
    lib/facil/fiobj/fiobj_ary.h
    lib/facil/fiobj/fiobj_data.c
    lib/facil/fiobj/fiobj_data.h
    lib/facil/fiobj/fiobj_hash.c
    lib/facil/fiobj/fiobj_hash.h
    lib/facil/fiobj/fiobj_json.c
    lib/facil/fiobj/fiobj_json.h
    lib/facil/fiobj/fiobj_mustache.c
    lib/facil/fiobj/fiobj_mustache.h
    lib/facil/fiobj/fiobj_numbers.c
    lib/facil/fiobj/fiobj_numbers.h
    lib/facil/fiobj/fiobj_str.c
    lib/facil/fiobj/fiobj_str.h
    lib/facil/fiobj/fiobject.c
    lib/facil/fiobj/fiobject.h
    lib/facil/fiobj/mustache_parser.h
    lib/facil/http/parsers/hpack.h
    lib/facil/http/parsers/http1_parser.h
    lib/facil/http/parsers/http_mime_parser.h
    lib/facil/http/parsers/websocket_parser.h
    lib/facil/http/http.c
    lib/facil/http/http.h
    lib/facil/http/http1.c
    lib/facil/http/http1.h
    lib/facil/http/http_internal.c
    lib/facil/http/http_internal.h
    lib/facil/http/websockets.c
    lib/facil/http/websockets.h
    lib/facil/legacy/fio_mem.c
    lib/facil/legacy/fio_mem.h
    lib/facil/redis/redis_engine.c
    lib/facil/redis/redis_engine.h
    lib/facil/redis/resp_parser.h
    lib/facil/tls/fio_tls.h
    lib/facil/tls/fio_tls_missing.c
    lib/facil/tls/fio_tls_openssl.c
    lib/facil/fio.c
    lib/facil/fio.h
    src/cli.c
    src/cli.h
    src/http_service.c
    src/http_service.h
    src/main.c
    src/main.h)
