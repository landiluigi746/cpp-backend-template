FROM gazzyt/alpine-build-vcpkg:1.8 AS builder
ARG BUILD_TYPE=Release
ENV PATH=${PATH}:${VCPKG_ROOT}

WORKDIR ${VCPKG_ROOT}
RUN git pull origin master

WORKDIR /app

COPY vcpkg.json .
RUN vcpkg install

COPY . .
RUN cmake -S . -B build -G "Ninja" \
    -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
    -DCMAKE_TOOLCHAIN_FILE=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake
RUN cmake --build build --parallel $(nproc)

FROM alpine:latest

WORKDIR /app
COPY --from=builder /app/bin/cpp-backend-template .
COPY --from=builder /usr/lib/* /usr/lib/

EXPOSE ${PORT}

CMD ["./cpp-backend-template"]
