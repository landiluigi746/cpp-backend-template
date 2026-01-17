.PHONY: up down logs logs-all devenv

up:
	@docker compose up --build -d

down:
	@docker compose down

logs:
	@docker compose logs cpp-backend-template

logs-all:
	@docker compose logs

devenv:
	@cmake -S . -B ./build \
	    -DCMAKE_BUILD_TYPE=RelWithDebInfo \
		-DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake
