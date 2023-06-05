
# 
function createDirIfNotSet() {
    if [ ! -d $1 ]; then
        mkdir $1
    fi
}

# 10 步进，100 步进
function create() {
    # 要创建的根目录
    rootDir=$1
    # 起始序列号
    startNumber=$(expr $2 / 10 \* 10 + 1)
    # 终止序列号
    endNumber=$3
    # 
    len=$(expr length $endNumber)

    for ((i=${startNumber}; i<=${endNumber}; i++));
    do 
        partStart=$(expr \( $i - 1 \) / 10 \* 10 + 1)
        partEnd=$(expr \( \( $i - 1 \) / 10 + 1 \) \* 10 )
        part="$(printf "%0${len}d" $partStart)-$(printf "%0${len}d" $partEnd)"
        filename=$(printf "%0${len}d" $i)

        partPath="${rootDir}/${part}"
        createDirIfNotSet ${partPath}
        dirPath="${rootDir}/${part}/${filename}"
        createDirIfNotSet ${dirPath}
    done
}

absPath=$(pwd)

# if not set ./src then create
srcPath=${absPath}/src
createDirIfNotSet ${srcPath}

# if not set ./src/weekly then create
weeklyPath=${srcPath}/weekly
createDirIfNotSet ${weeklyPath}

# if not set ./src/biweekly then create
biweeklyPath=${srcPath}/biweekly
createDirIfNotSet ${biweeklyPath}

#
create ${weeklyPath} 331 340

